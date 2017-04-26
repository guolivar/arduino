// suite('hello', () =>{
//     test('does something', (done)=>{
//         var expected = {
//             Dust: 12,
//             Temperature: 19,
//             Humidity: 123,
//             CO2: 14,
//             Decibals: 15,
//             Distance1: 61,
//             Distance2: 51,
//             Distance3: 32,
//             Distance4: 45,
//             Distance5: 14,
//             Distance6: 234,
//             Distance7: 23.4,
//             Presence: true,
//             Time: '1-23'
//         }

//         expect(extract('/12_19_123_14_15_61_51_32_45_14_234_23.4_true_1-23').equals(expected))
//         done()
//     })
// })

import test from 'ava';

test(t => {

     var expected = {
            Dust: 12,
            Temperature: 19,
            Humidity: 123,
            CO2: 14,
            Decibals: 15,
            Distance1: 61,
            Distance2: 51,
            Distance3: 32,
            Distance4: 45,
            Distance5: 14,
            Distance6: 234,
            Distance7: 23.4,
            Presence: true,
            Time: '1-23'
        }

	t.deepEqual(extract('/12_19_123_14_15_61_51_32_45_14_234_23.4_true_1-23'), [1, 2]);
});
