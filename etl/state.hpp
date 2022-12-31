/*
 *
 *
 */
#ifndef ETL_STATE_HPP
#define ETL_STATE_HPP

namespace etl {

    //
    // Concrete states are responsible for transitioning to one of their next states.
    // They do so by calling the protected member function 'set_current_state()'.
    template <typename T> class state
    {
    public:
        class context;
        friend class context;

        state(context& c);              // Each state needs to know its context,
                                        // which yields the current state in the 
                                        // application.
        
    protected:
        void transition(state<T>*);     // Must be invoked by the concrete state, to
                                        // perform the state transition.
      
    private:
        virtual void handle(T) = 0;     // Is invoked by the context. 
        virtual void on_entry();        // Feel free to override
        virtual void on_exit();  
            
        context& m_context;
    };
    
    template <typename T> class state<T>::context
    {
    public:
        context();
        void request(T);
        void set_current_state(state<T>*);
      
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
    
    template <typename T> void state<T>::transition(state<T>* s)
    {
        m_context.set_current_state(s);
    }
    
    template <typename T> void state<T>::on_entry()
    {
    }

    template <typename T> void state<T>::on_exit()
    {
    }

    //
    // Implementation: state::context
    //

    template <typename T> state<T>::context::context()
    : m_state(nullptr)
    {
    }

    template <typename T> void state<T>::context::request(T t)
    {
        if ( m_state ) 
            m_state->handle(t);
    }
    
    template <typename T> void state<T>::context::set_current_state(state<T>* s)
    {
        if ( m_state )
        {
            m_state->on_exit();
        }
        m_state = s;
        if ( m_state )
        {
            m_state->on_entry(); 
        }
    }


} /* namespace etl */
#endif
