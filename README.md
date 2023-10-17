# polymorphism_impl
This project is a study of different ways of implementing polymorphism in C++.
The three ways currently implemented are dynamic polymorphism, union-based polymorphism, and std::variant-based polymorphism.
BasicShape.hpp provides stand-alone definitions of shape types and shape functions (functions that accept the shapes as parameters).
The shapes currently defined are Circle and struct AARect.
The shape functions defined allow for the calculation of the area of any shape, checking for a collision between a pair of any two shapes.

The task of polymorphism implementation is to enable shapes of different types to be stored in a common container, handled without knowledge of their underlying type through the implementation of generalized shape functions.
Something resembling the following code should be possible:
```
std::vector<GeneralShape> shapes{Circle(), AARect(), ...};
auto a = area(shapes.at(n));
auto c = collide(shapes.at(m), shapes.at(n));
```
The possibility of adding new shape types and shape functions should be considered.

## Dynamic Polymorphism
Implementation of dynamic polymorphism is provided in the ShapesVirtual.hpp header.
It is achieved through the implementation of the IGeneralShape interface by CircleShape and AARectShape classes.
IGeneralShape declares ```virtual float area() const = 0;```, which is then implemented in each of the derived classes.
I couldn't find a solution for implementing collision detection ```virtual float collides(const IGeneralShape&) = 0;``` that I would find satisfactory.

One possible solution is declaring ```virtual float collides(const SpecificShape&) const = 0;``` for every possible shape and implementing them in every derived class.
This solution, given that collision detection between different shapes is already defined in BasicShapes, seems like a repetition of the work that has already been done.
If we imagined adding new shapes or interactions between shapes, the number of combinations we'd have to account for and duplicate would grow exponentially.

Another solution is casting IGeneralShape down to a specific shape object, which would also require implementing something like ```virtual EShape get_shape_etype() = 0;```.
This solution seems like a struggle against the obstacle introduced by the decision to use dynamic polymorphism.
Ew!

## Union-based polymorphism
Implementation of union-based polymorphism is available in the ShapesUnion.hpp header.
This approach relies on the ability to store objects of different types in the same memory location (one at a time, of course) with ```union```.
A ShapeUnion object holds a union of basic shapes and an EShape enum, with a value corresponding to the shape type currently stored in the union.
A switch statement is used to retrieve and handle the basic shape object.
An implementation of a single function is sufficient to determine the area of a ShapesUnion, a single template function is enough to check for collision between two ShapesUnions.

Some drawback of the approach is that every shape function implementation requires a switch statement, and every new shape type requires adding a new case in the already implemented shape functions.
Perhaps, this could be mitigated using preprocessor directives, but I didn't explore this option further.

## Variant-based polymorphism
Implementation of variant-based polymorphism is available in the ShapesVariant.hpp header.
At the basis of this implementation is the usage of std::variant<BasicShapeTypes...> to represent a general shape.
This approach has many of the benefits of the union-based implementation.
One additional benefit is that adding new shape types only requires adding the new types to the std::variant parameter list.

Implementation of the shape functions can still be a bit verbose. This is an example of a possible area function implementation:
```
template<size_t N = 0, typename ...Shapes_t>
float area(const std::variant<Shapes_t...>& var) {
    // this check prevents the compiler from attempting to use an std::get function with an out-of-bound index
    if constexpr (N+1 == std::variant_size_v<typeof(var)>) {
        return area(std::get<N>(var));
    } else {
        if(var.index() == N) {
            return area(std::get<N>(var));
        } else {
            return area<N+1>(var);
        }
    }
}
```
There was an attempt to use a macro to extract some of the verbosity and simplify shape functions implementation, resulting in the following ugly, but functional implementation:
```
template<size_t N = 0, typename ...Shapes_t>
float area(const std::variant<Shapes_t...>& var) {
    VARIANT_APPLY(var, N,
                  area(std::get<N>(var)),
                  area<N+1>(var))
}
```
