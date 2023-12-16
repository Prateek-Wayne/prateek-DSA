/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe:(val1)=>{
        if(val1===val)
            return val1===val;
        else
            throw new Error("Not Equal");
        },
        notToBe:(val1)=>{
            if(val1!==val)
                {
                    return true;
                }
            else
            {
                throw new Error("Equal");
            }
        }  
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */