try {
        std::vector<int> arr;
        arr.at(6);
    } catch (std::out_of_range err) {
        cout << err.what() << endl;
    }