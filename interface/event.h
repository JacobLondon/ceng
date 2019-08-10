#ifndef EVENT_H
#define EVENT_H

typedef struct Event {
    unsigned int code;
    void (* action)();
} Event;

#define EVENT_INIT(_code, _action) { \
    .code = _code, \
    .action = _action, \
}

#endif // EVENT_H