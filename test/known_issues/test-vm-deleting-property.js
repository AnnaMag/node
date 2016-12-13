'use strict';
// Refs:https://github.com/nodejs/node/issues/6287

require('../common');
const assert = require('assert');
const vm = require('vm');

var context = vm.createContext();
const res = vm.runInContext(`
  this.x = 'prop';
  delete this.x;
  Object.getOwnPropertyDescriptor(this, "x");
`, context);

assert.equal(res.value, undefined); 
