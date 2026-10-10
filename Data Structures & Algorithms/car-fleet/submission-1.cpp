class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> cars(position.size());
        for (int i = 0; i < position.size(); i++) {
            cars[i] = {position[i], speed[i]};
        }

        std::sort(cars.rbegin(), cars.rend());

        std::stack<double> st;

        for (int i = 0; i < cars.size(); i++) {
            double timeToArrive = static_cast<double>(target - cars[i].first) / cars[i].second;
            if (st.empty() || st.top() < timeToArrive) {
                st.push(timeToArrive);
            }
        }

        return st.size();

    }
};
