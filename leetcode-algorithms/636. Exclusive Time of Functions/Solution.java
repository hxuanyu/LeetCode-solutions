class task {
    public task(int id) {this.id = id;}
    List<Integer> time = new ArrayList<>();
    int id;
}

class Solution636 {
    public int[] exclusiveTime(int n, List<String> logs) {
        TreeMap<Integer, Integer> rslt = new TreeMap<>();

        Stack<task> taskque = new Stack<>();

        for (String log : logs) {
            String[] items = log.split(":");
            int id = Integer.valueOf(items[0]);
            boolean start = items[1].equals("start");
            int time = Integer.valueOf(items[2]);

            if (taskque.isEmpty()) {
                task newtask = new task(id);
                newtask.time.add(time);
                taskque.push(newtask);
            } else {
                if (!start) { //
                    task currenttask = taskque.pop();
                    currenttask.time.add(time);

                    int totaltime = 0;
                    for (int i = 0; i < currenttask.time.size(); i += 2) {
                        if (i + 1 < currenttask.time.size())
                            totaltime += currenttask.time.get(i + 1) - currenttask.time.get(i) + 1;
                    }

                    rslt.put(currenttask.id, rslt.getOrDefault(currenttask.id, 0) + totaltime);

                    if (!taskque.isEmpty()) {
                        task nextask = taskque.pop();
                        nextask.time.add(time + 1);
                        taskque.push(nextask);
                    }

                } else { // if new start;
                    task newtask = new task(id);
                    newtask.time.add(time);

                    task oldtask = taskque.pop();
                    oldtask.time.add(time - 1);

                    taskque.push(oldtask);
                    taskque.push(newtask);
                }
            }
        }

        int[] rr = new int[rslt.size()];
        for (Map.Entry<Integer, Integer> entry : rslt.entrySet()) {
            rr[entry.getKey()] = entry.getValue();
        }


        return rr;
    }
}
