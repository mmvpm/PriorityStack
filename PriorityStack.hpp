#include <tuple>
#include <queue>

template <class T>
class PriorityStack {
public:
    void Push(int priority, T value) {
        ++order_counter; // for LIFO
        _queue.emplace(order_counter, priority, value);
    }

    T Pop() {
        Element element = _queue.top();
        _queue.pop();
        return element.value;
    }

    bool IsEmpty() {
        return _queue.empty();
    }

    void Clear() {
        order_counter = 0;
        _queue = queue_t();
    }

private:
    using counter_t = uint64_t;

    struct Element {
        counter_t number_in_order;
        int priority;
        T value;

        Element(counter_t number_in_order, int priority, T value) :
            number_in_order(number_in_order),
            priority(priority),
            value(value) {}

        bool operator <(const Element& other) const {
            return priority <  other.priority
                || priority == other.priority && number_in_order < other.number_in_order;
        }
    };

    using queue_t = std::priority_queue<Element>;

    queue_t _queue;
    counter_t order_counter = 0;
};
