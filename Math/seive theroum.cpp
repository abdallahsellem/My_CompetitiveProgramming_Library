
    for (int i = 0; i <= 1e7; i++)
        prime[i] = true;

    for (int p = 2; p * p <= 1e7; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= 1e7; i += p)
                prime[i] = false;
        }
    }
    vector<int> vec;
    for (int i = 2; i <= sqrt(1e7); i++)

        if (prime[i]) {
            vec.push_back(i);
        }