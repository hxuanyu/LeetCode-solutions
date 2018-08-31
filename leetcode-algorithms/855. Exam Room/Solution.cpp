// In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.
//
// When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the room, then the student sits at seat number 0.)
//
// Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() returning an int representing what seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.
//
//
//
// Example 1:
//
// Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
// Output: [null,0,9,4,2,null,5]
// Explanation:
// ExamRoom(10) -> null
// seat() -> 0, no one is in the room, then the student sits at seat number 0.
// seat() -> 9, the student sits at the last seat number 9.
// seat() -> 4, the student sits at the last seat number 4.
// seat() -> 2, the student sits at the last seat number 2.
// leave(4) -> null
// seat() -> 5, the student​​​​​​​ sits at the last seat number 5.
// ​​​​​​​
//
// Note:
//
// 1 <= N <= 10^9
// ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across all test cases.
// Calls to ExamRoom.leave(p) are guaranteed to have a student currently sitting in seat number p.
class ExamRoom {
public:
    ExamRoom(int N) {
        this->N = N;
    }

    int seat() {
        if (person.empty()) {
            person.insert(0);
            return 0;
        } else {
            int maxdis = 0;
            auto iter = person.begin();
            int pos = 0;
            if (*iter != 0) {
                maxdis = *iter;
                pos = 0;
            }

            int localdis = 0;
            for (; iter != person.end(); iter++) {
                auto c = iter;
                c++;
                if (c == person.end()) break;
                localdis = (*c - *iter) / 2;
                if (localdis > maxdis) {
                    maxdis = localdis;
                    pos = *iter + localdis;
                }
            }

            if (*iter != N - 1) {
                localdis = N - 1 - *iter;
                if (localdis > maxdis) {
                    maxdis = localdis;
                    pos = N - 1;
                }
            }
            person.insert(pos);
            return pos;
        }
    }

    void leave(int p) {
        person.erase(p);
    }

    set<int> person;
    int N;
};
