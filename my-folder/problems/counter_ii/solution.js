/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let reseted=init;
    return {
        increment:()=>{
            reseted+=1;
            return reseted;
        },
        decrement:()=>{
            reseted-=1;
            return reseted;
        },
        reset:()=>{
            reseted=init
            return init;
        }
        
        
        
        
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */