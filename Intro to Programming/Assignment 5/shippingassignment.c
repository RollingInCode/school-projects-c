//
// main.c
// Shipping Charges
//
// Created by Stephanie Couto on 2/10/19.
// Copyright © 2019 Stephanie Couto. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    double distance, weight, weightCharges = 0, shippingCharge, distanceCharge = 0, unableToShip;
    int ship = 1; // We will use this to flag whether or not the package is being shipped due to weight. Assume it is being shipped
    int segments = 0;
    printf ("Enter the weight of the package:\n");
    scanf ("%lf", &weight);
    printf ("Enter the distance your package needs to go: \n");
    scanf ("%lf", &distance);
    
    if ((int) distance % 500 != 0)
        segments = (int) distance / 500 + 1; // cost is calculated by 500 mile segments. This computes the number of segments with one extra segment for part of 500 miles
    else
        segments = (int) distance / 500;  // If the distance is an exact multiple of 500, don't add one extra segment.
    
    if (weight <= 10)
        weightCharges = segments * 3.00;
    else
        if (weight <= 50)
            weightCharges = segments * 5.00;
        else {
            printf ("We cannot ship a package over 50 pounds\n");
            ship = 0;  // to heavy to ship, set flag to zero
        }
    
    if (ship == 1) {
    if (distance > 1000)
        distanceCharge = 10;
    shippingCharge = weightCharges + distanceCharge;
    unableToShip = weight > 50;
    
    printf ("Your total cost is: %.2lf \n", shippingCharge);
    //printf ("We're unable to ship your package \n", unableToShip);
    }
    
}

