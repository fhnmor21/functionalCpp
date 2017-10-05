#ifndef FUNCTOR_HPP
#define FUNCTOR_HPP

#include "function.hpp"
#include "type_utils.hpp"

namespace FunctionalCpp
{
  //  ===
  // functor wrapper (static class)
  template < class ArrowA2B, class FunctorOf_A, class FunctorOf_B >
  struct Functor
  {
    // fmap :: (a -> b) -> f a -> f b
    static FunctorOf_B fmap(const ArrowA2B a2b, const FunctorOf_A& fa);
  };

  //  ===
  // Applicative wrapper (static class)
  template < class FunctorOf_A2B, class FunctorOf_A, class FunctorOf_B >
  struct Applicative : Functor< FunctorOf_A2B, FunctorOf_A, FunctorOf_B >
  {
    // apply :: f (a -> b) -> f a -> f b
    static FunctorOf_B apply(const FunctorOf_A2B& fa2b, const FunctorOf_A& fa);
  };

} // end namespace FunctionalCpp

#endif // FUNCTOR_HPP
