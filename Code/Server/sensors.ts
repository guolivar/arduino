import { Column, Entity, PrimaryGeneratedColumn } from 'typeorm';
    

declare namespace Sensors{
    
    private abstract class Sensor{
        @PrimaryGeneratedColumn()
        id: number
        abstract calculate: Function
    }
    
    @Entity()
    export class IR extends Sensor{
        @Column()
        distance: number

        function calculate (){ return 1 + 2 }
    }

    @Entity()
    export class Dust extends Sensor{
    
        pm1: number
        
        /**
         * PM 2.5
         * @type {number}
         * @memberOf Dust
         */
        @Column()
        pm25: number

         /**
         * PM 10
         * @type {number}
         * @memberOf Dust
         */
        @Column()
        pm10: number

        calculate = () => { return 1 + 2 }
    }

    @Entity()
    export class PIR extends Sensor{

        @Column()
        moving: boolean

        calculate = () => { return 1 + 2 }
    }

    @Entity()
    export class CO2 extends Sensor{
        @Column()
        value: number

        calculate = () => { return 1 + 2 }
    }

    @Entity()
    export class Temp extends Sensor{

        @Column()
        temperature: number

        @Column()
        humidity: number

        calculate = () => { return 1 + 2 }
    }
}