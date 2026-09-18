var createCounter = function(init) {

    let current = init;

    function increment() {
        return ++current;
    }

    function decrement() {
        return --current;
    }

    function reset() {
        current = init;
        return current;
    }

    return {
        increment,
        decrement,
        reset
    };
};