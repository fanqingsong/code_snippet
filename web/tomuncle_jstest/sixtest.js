
找出数字数组中最大的元素（使用Match.max函数）

var numArr = [
  1,
  2,
  44
];
console.log(Math.max.apply(null, numArr))

--- call to arr
// 将 1， 3， 3 转换为素组调用
function test(){
  for(var index in arguments[0]){
     console.log(arguments[0][index])
  }
}

//test([1, 3]);
//test.call(null, 1, 3);

function testCall(){
   test(Array.prototype.slice.call(arguments))
}
testCall(1, 3);

----
转化一个数字数组为function数组（每个function都弹出相应的数字）
var numArr = [
  1,
  2,
  44
];

for (i in numArr)
{
  numArr[i] = (function(num){
    return function()
    {
      console.log(num)
    }
  })(numArr[i]);
}

for (i in numArr)
{
  numArr[i]();
}


------
给object数组进行排序（排序条件是每个元素对象的属性个数）

var numArr = [
  {"a":"b"},
  {"a":"b", "oo":"pp", "uu":"qq"},
  {"a":"b", "ll":"b"}
];

console.log("numArr is Array="+(numArr instanceof Array))

var i = 0
var tmp = numArr[i];
console.log("tmp="+tmp)

function GetPropertyNum(obj){
  var num = 0;
  for (var key in obj){
    if ( obj.hasOwnProperty(key) )
    {
        num ++;
    }
  }
  return num;
}

// test GetPropertyNum
console.log(GetPropertyNum({"a":"b"}))

//使用冒泡排序
function BubbleSort(arr, cmpFunc)
{
  for( var i=0; i<=arr.length-2; i++ )
  {
    for ( var j=0; j<=arr.length-2-i; j++ )
    {
      //前一个大于后一个
      var pre = arr[j];
      var next = arr[j+1];
      if ( cmpFunc(pre,next) > 0 )
      {
         var tmpObj = arr[j];
         arr[j] = arr[j+1];
         arr[j+1] = tmpObj;
      }
    }
  }
}

function ObjectPropertyCmp(obj1, obj2)
{
  var preCount = GetPropertyNum(obj1);
  var nextCount = GetPropertyNum(obj2);
 
  if ( preCount > nextCount )
  {
    return 1;
  }
  else if ( preCount === nextCount )
  {
    return 0;
  }
  else
  {
    return -1
  }
}

console.log("----- before buble sort -----------")
for (var i in numArr){
  console.log(numArr[i]);
}

BubbleSort(numArr, ObjectPropertyCmp);

console.log("----- after buble sort -----------")
for (var i in numArr){
  console.log(numArr[i]);
}




-------- fibonaci ----
function createFibonaci()
{
  var prev = 0;
  var current = 1;
 
  return function(){
    var result = prev + current;
    prev = current;
    current = result;
    
    return current;
  }
}

function printFibonaci(order)
{
  var fiboArr = [0, 1];
  var fibonaciGenerator = createFibonaci();
 
  for( var i=2; i<=order; i++ )
  {
    fiboArr.push(fibonaciGenerator());
  }
 
  for ( var i in fiboArr )
  {
    console.log("fibo index="+i+"; fibonum="+fiboArr[i]);
  }
}

printFibonaci(8);



------
实现如下语法的功能：var a = (5).plus(3).minus(6); //2

// Number类型值转换为 Number对象
var numObj = new Number(5);
console.log("numObj type="+typeof numObj);
// Number对象获取 Number类型值
var num = numObj.valueOf();
console.log("num = "+num);
console.log("num type="+typeof num);


Number.prototype.plus = function(num){
  var thisNum = this.valueOf();
  return thisNum + num;
}

Number.prototype.minus = function(num){
  var thisNum = this.valueOf();
  return thisNum - num;
}

var a = (5).plus(3).minus(6);
console.log("a="+a);
----------------------
// 实现如下语法的功能：var a = add(2)(3)(4); //9
function createAddFunc()
{
  var sum = 0;

  function add(num){
    sum += num;
    
    return add;
  };

  add.valueOf = function(){
      return sum;  
  };
    
  return add;
}


var add = createAddFunc();

var a = add(2)(3)(4);

console.log("a="+a);//a = 9














