'use strict';
// Refs: https://github.com/nodejs/node/issues/10223

require('../common');
const vm = require('vm');
const assert = require('assert');

const code = `
   Object.defineProperty(this, 'foo', {value: 5});
   var desc = Object.getOwnPropertyDescriptor(this, 'foo');
   desc.writable;
`;

const sandbox = {console}
const ctx = vm.createContext(sandbox);

assert.strictEqual(vm.runInContext(code, ctx), false);
