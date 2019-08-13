//Inside one.js:
define(function(require, exports, module) {
      var two = require('./two.js');

      exports.sayHello = function() {
        console.log('one module called');
      };

      exports.callTwo = function() {
        two.sayHello();
      };
    }
);