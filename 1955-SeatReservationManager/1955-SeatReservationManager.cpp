// Last updated: 10/5/2025, 8:53:51 AM
class SeatManager {
public:
       set<int> unreserved ;
        vector<int> reserved ;
    SeatManager(int n) {
        for(int i=1 ; i<=n ; i++)
        {
            unreserved.insert(i);
        }
        
    }
    
    int reserve() {
        auto seat_to_reseve = unreserved.begin();
        int seat = *(seat_to_reseve);
        reserved.push_back(seat);
        unreserved.erase(seat);
        return seat;
        
    }
    
    void unreserve(int seatNumber) {
        int unreserve_seat = seatNumber;
         auto newEnd = std::remove(reserved.begin(), reserved.end(), seatNumber);
         reserved.erase(newEnd, reserved.end());
         unreserved.insert(unreserve_seat);
        
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */