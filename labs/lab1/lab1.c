#include <stdio.h>
#include <math.h>

const double RADIUS_EARTH = 6368.0; //in km

typedef struct Location_struct {
    char name[50];    //city name
    double latitude;
    double longitude;
    double elevation;
} Location;

typedef struct WorldTour_struct {
    Location locs[5];
    double distances[5];
} WorldTour;

double calcDist(double lat1, double long1, double lat2, double long2){
    return RADIUS_EARTH*acos(cos(lat1*M_PI/180.0)*cos(lat2*M_PI/180.0)*cos((long2-long1)*M_PI/180.0) + sin(lat1*M_PI/180.0)*sin(lat2*M_PI/180.0));
}

WorldTour setDists(WorldTour aTrip) {
    //TODO: set the distances array elements for aTrip as the great-circle-distances between 
    //      sequential Locations in the locs array. 
    //      Note: after the final city, the World Tour returns back to the starting city
    //      Note: aTrip is passed by value; best practice is to make a copy to update and return

    WorldTour copyTrip = aTrip;

    for(int i = 0; i < 4; i++){
        copyTrip.distances[i] = calcDist(copyTrip.locs[i].latitude, copyTrip.locs[i].longitude, copyTrip.locs[i+1].latitude, copyTrip.locs[i+1].longitude);
    }

    copyTrip.distances[4] = calcDist(copyTrip.locs[4].latitude, copyTrip.locs[4].longitude, copyTrip.locs[0].latitude, copyTrip.locs[0].longitude);

    return copyTrip; //modify this return statement
}

int main() {

    WorldTour myTrip;

    for (int i=0;i<5;i++) {
        printf("City %d:\n",i+1);
        printf("Enter the city name:\n");

        //TODO: read in the city name for the i'th location; save in the Location struct array in myTrip
        scanf("%s", myTrip.locs[i].name);
        printf("Enter the city coordinates (lat long elev):\n");
        
        //TODO: with a single call to scanf(), read in the (lat, long, elev) data for the i'th location; 
        //      save in the Location struct array in myTrip
        scanf("%lf %lf %lf", &myTrip.locs[i].latitude, &myTrip.locs[i].longitude, &myTrip.locs[i].elevation);

        
    }
    
    //set the distances array subitem of myTrip
    myTrip = setDists(myTrip);

    //TODO: print out the summary of the World Tour in the specified format 

    for (int i = 0; i < 4; i++){
        printf("Leg %d - %s to %s: %.2f km\n", i+1, myTrip.locs[i].name, myTrip.locs[i+1].name, myTrip.distances[i]);
    }

    printf("Leg 5 - %s to %s: %.2f km\n", myTrip.locs[4].name, myTrip.locs[0].name, myTrip.distances[4]);

    return 0;
}