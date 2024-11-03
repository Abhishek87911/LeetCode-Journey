/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let map = new Map()

    for(let i=0 ;i < nums.length;i++)
    {
        if(!map.has(nums[i])){
            map.set(nums[i],1)
        }
        else {
            map.set(nums[i],map.get(nums[i])+1)
        }
    }

    let max = 0
    map.forEach(ele => {
        if(ele>max){
            max=ele
        }
    })

    for(let i=0;i<nums.length;i++)
    {
        if(map.get(nums[i]) === max) return nums[i]
    }

};