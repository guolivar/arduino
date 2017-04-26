"use strict";
var __extends = (this && this.__extends) || function (d, b) {
    for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p];
    function __() { this.constructor = d; }
    d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
};
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
var __metadata = (this && this.__metadata) || function (k, v) {
    if (typeof Reflect === "object" && typeof Reflect.metadata === "function") return Reflect.metadata(k, v);
};
var typeorm_1 = require("typeorm");
var Sensors;
(function (Sensors) {
    var Sensor = (function () {
        function Sensor() {
        }
        __decorate([
            typeorm_1.PrimaryColumn("int", { generated: true }), 
            __metadata('design:type', Number)
        ], Sensor.prototype, "id", void 0);
        return Sensor;
    }());
    var IR = (function (_super) {
        __extends(IR, _super);
        function IR() {
            _super.apply(this, arguments);
            this.calculate = function () { return 1 + 2; };
        }
        IR = __decorate([
            typeorm_1.Entity(), 
            __metadata('design:paramtypes', [])
        ], IR);
        return IR;
    }(Sensor));
    var Dust = (function (_super) {
        __extends(Dust, _super);
        function Dust() {
            _super.apply(this, arguments);
            this.calculate = function () { return 1 + 2; };
        }
        Dust = __decorate([
            typeorm_1.Entity(), 
            __metadata('design:paramtypes', [])
        ], Dust);
        return Dust;
    }(Sensor));
    var PIR = (function (_super) {
        __extends(PIR, _super);
        function PIR() {
            _super.apply(this, arguments);
            this.calculate = function () { return 1 + 2; };
        }
        PIR = __decorate([
            typeorm_1.Entity(), 
            __metadata('design:paramtypes', [])
        ], PIR);
        return PIR;
    }(Sensor));
    var CO2 = (function (_super) {
        __extends(CO2, _super);
        function CO2() {
            _super.apply(this, arguments);
            this.calculate = function () { return 1 + 2; };
        }
        CO2 = __decorate([
            typeorm_1.Entity(), 
            __metadata('design:paramtypes', [])
        ], CO2);
        return CO2;
    }(Sensor));
    var Temp = (function (_super) {
        __extends(Temp, _super);
        function Temp() {
            _super.apply(this, arguments);
            this.calculate = function () { return 1 + 2; };
        }
        Temp = __decorate([
            typeorm_1.Entity(), 
            __metadata('design:paramtypes', [])
        ], Temp);
        return Temp;
    }(Sensor));
})(Sensors || (Sensors = {}));
