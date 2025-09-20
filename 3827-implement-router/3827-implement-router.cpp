
struct Packet {
    int source, destination, timestamp;
};

class Router {
private:
    int memoryLimit;
    queue<Packet> packets; // FIFO storage
    unordered_set<string> packetSet; // for duplicates
    unordered_map<int, vector<int>> destTimestamps; // destination -> sorted timestamps

    // helper to create unique key for duplicate check
    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        // check duplicate
        if (packetSet.count(key)) return false;

        // remove oldest if limit exceeded
        if ((int)packets.size() == memoryLimit) {
            Packet oldest = packets.front();
            packets.pop();
            string oldKey = makeKey(oldest.source, oldest.destination, oldest.timestamp);
            packetSet.erase(oldKey);

            // remove from destTimestamps
            auto &vec = destTimestamps[oldest.destination];
            vec.erase(lower_bound(vec.begin(), vec.end(), oldest.timestamp));
        }

        // add packet
        packets.push({source, destination, timestamp});
        packetSet.insert(key);
        destTimestamps[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty()) return {};

        Packet p = packets.front();
        packets.pop();

        string key = makeKey(p.source, p.destination, p.timestamp);
        packetSet.erase(key);

        // remove timestamp from destTimestamps
        auto &vec = destTimestamps[p.destination];
        vec.erase(lower_bound(vec.begin(), vec.end(), p.timestamp));

        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!destTimestamps.count(destination)) return 0;
        auto &vec = destTimestamps[destination];

        auto startIt = lower_bound(vec.begin(), vec.end(), startTime);
        auto endIt = upper_bound(vec.begin(), vec.end(), endTime);

        return (int)(endIt - startIt);
    }
};