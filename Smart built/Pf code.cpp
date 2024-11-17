#include<iostream>
using namespace std;

void printRooms(int n, double materialPerRoom, double bricksPerRoom, double cementPerRoom, double steelPerRoom) {
    for (int i = 1; i <= n; i++) {
        cout << "Room no: " << i << " - Material Quantity: " << materialPerRoom
             << " Bricks: " << bricksPerRoom << " units, Cement: " << cementPerRoom << " units, Steel: " << steelPerRoom 
			 << " units" << endl;
    }
}

int main() {
    int area, storey;
    cout << "Enter the area on which you want to build (consider the range of 3 to 20 marlas):" << endl;
    cin >> area;
    cout << "The area on which you want to build is: " << area << " marlas" << endl;

    if (area >= 3 && area <= 5) {
        cout << "Now choose the number of storeys for your building (max should be 2):" << endl;
        cin >> storey;
    } else if (area >= 6 && area <= 10) {
        cout << "Now choose the number of storeys for your building (max should be 3):" << endl;
        cin >> storey;
    } else if (area >= 11 && area <= 20) {
        cout << "Now choose the number of storeys for your building (max should be 4):" << endl;
        cin >> storey;
    } else {
        cout << "You entered the wrong value." << endl;
        return 1;
    }

    double budget;
    cout << "Enter your budget for construction: $";
    cin >> budget;

    const int maxRoomsPerFloor = 5;  // Maximum rooms per floor

    double materialCostPerFloor[4];   //Material cost for each floor
    double bricksCostPerFloor[4];    // Bricks cost for each floor
    double cementCostPerFloor[4];    // Cement cost for each floor
    double steelCostPerFloor[4];     // Steel cost for each floor
    int roomsPerFloor[4];            // Number of rooms on each floor

    // Measurement scale for materials
    const string bricksScale = "imperial";
    const string cementScale = "kgs";
    const string steelScale = "kg/m^3";
    // Common calculations for material costs
    double materialCost = budget / storey;
    double bricksCost = materialCost * 0.4;
    double cementCost = materialCost * 0.3;
    double steelCost = materialCost * 0.2;

// Loop for each floor
for (int i = 0; i < storey; ++i) {
    cout << "Enter the number of rooms (consider the range of 0 to " << maxRoomsPerFloor << ") for floor " << i + 1 << ":" 
	<< endl;
    cin >> roomsPerFloor[i];

    // Assign material costs for each floor
    materialCostPerFloor[i] = materialCost;
    bricksCostPerFloor[i] = bricksCost;
    cementCostPerFloor[i] = cementCost;
    steelCostPerFloor[i] = steelCost;

    // Display material details for each floor
    cout << "\nMaterial Details for Floor " << i + 1 << ":\n";
    cout << "Material Cost For Flooring: $" << materialCostPerFloor[i] << "\n";
    cout << "Bricks Quantity: " << bricksCostPerFloor[i] << " " << bricksScale << "\n";
    cout << "Cement Quantity: " << cementCostPerFloor[i] << " " << cementScale << "\n";
    cout << "Steel Quantity: " << steelCostPerFloor[i] << " " << steelScale << "\n";

    // Divide material costs among rooms
    double materialPerRoom = materialCost / roomsPerFloor[i];
    double bricksPerRoom = bricksCost / roomsPerFloor[i];
    double cementPerRoom = cementCost / roomsPerFloor[i];
    double steelPerRoom = steelCost / roomsPerFloor[i];
    printRooms(roomsPerFloor[i], materialPerRoom, bricksPerRoom, cementPerRoom, steelPerRoom);
}

// Default case
if (storey < 1 || storey > 4) {
    cout << "Invalid number of storeys." << endl;
    return 1;
}
}
