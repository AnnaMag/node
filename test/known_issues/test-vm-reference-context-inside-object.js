//https://github.com/nodejs/node/issues/855
//references to context inside of a context fail when set as a property
//of another object
var common = require('../common');
var assert = require('assert');
var vm = require('vm');

var sandbox = {};
sandbox.document = { defaultView: sandbox };

sandbox.window = sandbox;

vm.createContext(sandbox);

vm.runInContext('var result_property = document.defaultView === this', sandbox);
vm.runInContext('var result_global = window === this', sandbox);

assert.equal(sandbox.result_property, false);
assert.equal(sandbox.result_global, true);
