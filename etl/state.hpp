/*
 *
 *
 */
#ifndef ETL_STATE_HPP
#define ETL_STATE_HPP

namespace etl {
  
	
  // Concrete states are responsible for transitioning to one of their next states.
  // They do so by calling the protected member function 'set_current_state()'.
	template <typename T> class state
	{
	  public:
      class context;

	    state(context& c);              
	    
      virtual void handle(T) = 0; // Is invoked by the context. 
	    virtual void trigger() = 0; // Is called when the state becomes the current state.
	  
    protected:
	    void set_current_state(state<T>*);
	  
    private:
	    context& m_context;
	};
	
	template <typename T> class state<T>::context
	{
	  public:
	    void request(T);
	    void set(state<T>*);
	  
    private:
	    state<T>* m_state;
	};
	
  //
  // Implementation: state
  //

  template <typename T> state<T>::state(context& c)
	: m_context(c)
	{
	}
	
	template <typename T> void state<T>::set_current_state(state<T>* s)
	{
	  m_context.set(s);
	}
  
  //
  // Implementation: state::context
  //

  template <typename T> void state<T>::context::request(T t)
	{
	  if ( m_state ) 
	    m_state->handle(t);
	}
	
	template <typename T> void state<T>::context::set(state<T>* s)
	{
	  m_state = s;
	  if ( m_state )
	    m_state->trigger(); 
	}
	

} /* namespace etl */
#endif
