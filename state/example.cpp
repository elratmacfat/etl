/*  
 *  Variation of the state pattern
 *
 *  Given circumstances
 *  -------------------
 *  - Using dynamic memory allocation is not allowed.
 *  - Each concrete state object is persistent, i.e. its lifetime
 *    does not end when a state transition occurs.
 *
 */
#include "etl/state.hpp"

#include <iostream>
#include <vector>

using namespace etl;

class state_a : public state<int>
{
  public:
    state_a(state<int>::context& cs) : state(cs) {
    }
    
    virtual void handle(int i) { 
      std::cout << "a: " << i << '\n'; 
      if ( i==5 )
        set_current_state(m_b);
    }

    virtual void trigger() {
      std::cout << "a: triggered\n"; 
    }

    void set_b(state<int>* b) {
      m_b = b;
    }

  private:
    state<int>* m_b;
};

class state_b : public state<int>
{
  public:
    state_b(state<int>::context& cs) : state(cs) {
    }
    
    virtual void handle(int i) { 
      std::cout << "b: " << i << '\n'; 
      if ( i == 8 )
        set_current_state(m_a);
    }
    
    virtual void trigger() {
      std::cout << "b: triggered\n"; 
    }

    void set_a(state<int>* a) {
      m_a = a;
    }

  private:
    state<int>* m_a;

};

int main()
{
  state<int>::context cs;
  
  state_a a(cs);
  state_b b(cs);

  a.set_b(&b);
  b.set_a(&a);

  cs.set(&a);

  std::vector<int> data{1,2,3,4,5,6,7,8,9,10};
  for(auto& d : data )
    cs.request(d);

  return 0;
}
