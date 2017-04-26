import * as fs from 'fs'
import { parse } from 'toml'

// fs.watch('../Shared', {encoding: 'utf8'}, (eventType, filename) => {
//   if (filename)
//     var text = fs.readFile(filename, 'utf8')
// });

console.log(parse(fs.readFileSync('../../Shared/sensors.toml', 'utf8')))

// for sensor in ^ generate code in each lang