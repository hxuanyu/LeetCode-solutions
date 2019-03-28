/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/
class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Queue<Employee> que = new LinkedList<>();

        Map<Integer, Employee> vmap = new HashMap<>();
        for (Employee e : employees) {
        	if (e.id == id) {
        		que.add(e);
        	}
        	vmap.put(e.id, e);
        }

        int total = 0;
        while (!que.isEmpty()) {
        	int size = que.size();
        	for (int i = 0; i < size; i++) {
        		Employee e = que.poll();
        		total += e.importance;

        		for (Integer id_ : e.subordinates) {
        			que.add(vmap.get(id_));
        		}
        	}
        }

        return total;
    }
}
