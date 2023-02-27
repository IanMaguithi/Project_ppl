#include <LiquidCrystal_I2C.h>
#include <math.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2);

// Threshold values for flow rate, pressure, and tank level
const double threshold_flow_rate = 50.0;
const double threshold_pressure = 50.0;
const double threshold_tank_level = 2900.0;

// Maximum capacities of tanks
const double max_tank_1 = 3000.0;
const double max_tank_2 = 3000.0;
const double max_tank_3 = 3000.0;

// Distance between depots in km
const double distance = 700;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  // lcd.begin(16, 2);
}

// Function to read flow rate from sensor
double read_flow_rate_sensor() 
{
    double flow_rate;
    Serial.println("Enter flow rate in m^3/hour: ");
    flow_rate = Serial.read();
    return flow_rate;
}

// Function to read pressure from sensor
double read_pressure_sensor() {
    double pressure;
    Serial.println("Enter pressure in psi: ");
    pressure = Serial.read();
    return pressure;
}

// Function to read tank levels
double read_tank_level(int tank_number) {
    double tank_level;
    if (tank_number == 1) {
        Serial.println("Enter tank 1 level in m^3: ");
        tank_level = Serial.read();
    }
    else if (tank_number == 2) {
        Serial.println("Enter tank 2 level in m^3: ");
        tank_level = Serial.read();
    }
    else if (tank_number == 3) {
        Serial.println("Enter tank 3 level in m^3: ");
        tank_level = Serial.read();
    }
    return tank_level;
}

// Function to control flow into a specific tank
void flow_into_tank(int tank_number) {
    if (tank_number == 1) {
        Serial.println("Flowing into tank 1");
    }
    else if (tank_number == 2) {
        Serial.println("Flowing into tank 2");
    }
    else if (tank_number == 3) {
        Serial.println("Flowing into tank 3");
    }
}

// Function to changeover receipt
void changeover_receipt(int tank_number) {
    if (tank_number == 1) {
        Serial.println("Changing over receipt to tank 1");
    }
    else if (tank_number == 2) {
        Serial.println("Changing over receipt to tank 2");
    }
    else if (tank_number == 3) {
        Serial.println("Changing over receipt to tank 3");
    }
}

// Function to calculate time to fill up a tank
double time_to_fill_up(double flow_rate, double ullage) {
    return ullage / flow_rate;
}

// Function to estimate time of arrival of a product
double estimate_time_of_arrival(double flow_rate, double interface_distance) {
    double speed = flow_rate / (distance - interface_distance); // calculate speed in m^3/km-hour
    double hours = distance / speed; // calculate time in hours
    return hours;
}
// Function to display data on the LCD screen
void display_on_LCD(double flow_rate, double pressure, double tank_level, double time_to_fill, double arrival_time) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Flow Rate: ");
    lcd.print(flow_rate);
    lcd.setCursor(2, 1);
    lcd.print("Pressure: ");
    lcd.print(pressure);
    delay(2000); 

    lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print("Tank Level: ");
    lcd.print(tank_level);
    lcd.setCursor(0, 1);  
    lcd.print("Time to fill: ");
    lcd.print(time_to_fill);
    lcd.print(" h");
    delay(2000);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  // int current_tank = 1;
  // double ullage;
  // double interface_distance;
  // // Set initial values for tank levels
  // double tank1_level = 2000.0;
  // double tank2_level = 2500.0;
  // double tank3_level = 1200.0;
  display_on_LCD(23,34,7800,6700,7899);
  // while (true) 
  // {
  //         }    
  //     // Read flow rate and pressure from sensors
  //     double flow_rate = read_flow_rate_sensor();
  //     double pressure = read_pressure_sensor();
  //     // Read tank levels from tanks
  //     tank1_level = read_tank_level(1);
  //     tank2_level = read_tank_level(2);
  //     tank3_level = read_tank_level(3);
  //     // if flow rate is greater than threshold and tank level is less than threshold
  //     if (flow_rate > threshold_flow_rate && tank1_level < threshold_tank_level) {
  //         flow_into_tank(current_tank);
  //         // calculate time to fill up tank
  //         ullage = threshold_tank_level - tank1_level;
  //         double time_to_fill = time_to_fill_up(flow_rate, ullage);
  //         // Check if an interface is arriving
  //         if (interface_distance > 0) {
  //             double arrival_time = estimate_time_of_arrival(flow_rate, interface_distance);
  //             display_on_LCD(flow_rate, pressure, tank1_level, time_to_fill, arrival_time);
  //         }
  //         else {
  //             display_on_LCD(flow_rate, pressure, tank1_level, time_to_fill, 0);
  //         }
  //         if (time_to_fill <= 1) {
  //             if (ullage == 0) {
  //                 Serial.println("Advice for offline 1 hour prior to the tank filling up.");
  //             }
  //             // Check if tank 2 or 3 has more ullage than tank 1
  //             else if (tank2_level - threshold_tank_level > ullage) {
  //                 current_tank = 2;
  //             }
  //             else if (tank3_level - threshold_tank_level > ullage) {
  //                 current_tank = 3;
  //             }
  //         }
  //     }
  //     else if (pressure > threshold_pressure) {
  //         changeover_receipt(2);
  //     }
  //}
}
