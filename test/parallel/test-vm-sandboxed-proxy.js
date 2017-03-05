'use strict';

require('../common');
const assert = require('assert');
const vm = require('vm');

// Handle a sandbox that throws while copying properties
const handler = {
    getOwnPropertyDescriptor: (target, prop) => {
      throw new Error('whoops');
    }
  };
const sandbox = new Proxy({foo: 'bar'}, handler);
const context = vm.createContext(sandbox);

vm.runInContext('', context);
