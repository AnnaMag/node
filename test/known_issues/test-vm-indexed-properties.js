'use strict';

require('../common');
const assert = require('assert');
const vm = require('vm');

const code =
    '  Object.defineProperty(this, 99 , {\n' +
    '  value: 20,' +
    '  enumerable: true' +
    '});';

const sandbox = {console}
let ctx = vm.createContext(sandbox);
vm.runInContext(code, ctx)

assert.strictEqual(sandbox[99], 20); //  sandbox[99] is undefined
