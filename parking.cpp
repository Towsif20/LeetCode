class ParkingSystem
{
    int capacity[3];
    int count[3];

public:
    ParkingSystem(int big, int medium, int small)
    {
        capacity[0] = big;
        capacity[1] = medium;
        capacity[2] = small;

        for(int i=0;i<3;i++)
        {
            count[i] = 0;
        }
    }

    bool addCar(int carType)
    {
        int index = carType-1;

        if(count[index] == capacity[index])
            return false;

        count[index]++;

        return true;
    }
};