#ifndef EVENT_H
#define EVENT_H

/**
 * \brief Pair an SDL event type with a function
 */
typedef struct Event {
    unsigned int key;
    void (* action)();
} Event;

#define EVENT_INIT(_key, _action) (struct Event) { \
    .key = _key, \
    .action = _action, \
}

#endif // EVENT_H