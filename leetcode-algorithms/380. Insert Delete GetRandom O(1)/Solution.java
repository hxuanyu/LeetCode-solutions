class RandomizedSet {

    /** Initialize your data structure here. */
    public RandomizedSet() {
    
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (vmap.containsKey(val)) return false;

        ar.add(val);
        vmap.put(val, ar.indexOf(val)); // val - pos
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (!vmap.containsKey(val)) return false;

        int pos_to_remove = vmap.get(val);

        int lastpos = ar.size() - 1;
        int lastkey = ar.get(lastpos);

        ar.set(pos_to_remove, lastkey);
        vmap.put(lastkey, pos_to_remove);

        ar.remove(ar.size() - 1);
        vmap.remove(val);
        return true;
    }

    /** Get a random element from the set. */
    public int getRandom() {
        return ar.get(new Random().nextInt(ar.size()));
    }

    List<Integer> ar = new ArrayList<>();
    Map<Integer, Integer> vmap = new HashMap<>();
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
