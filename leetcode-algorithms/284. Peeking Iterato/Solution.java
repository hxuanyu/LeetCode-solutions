class PeekingIterator implements Iterator<Integer> {

    public PeekingIterator(Iterator<Integer> iterator) {
        // initialize any member here.
        iter =iterator;
    }

   // Returns the next element in the iteration without advancing the iterator.
    public Integer peek() {
        if (cached) {
            return cache;
        } else {
            cache = iter.next();
            cached = true;
            return cache;
        }
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    @Override
    public Integer next() {
        if (cached) {
            cached = false;
            return cache;
        } else {
            return iter.next();
        }
    }

    @Override
    public boolean hasNext() {
        if (cached) return true;
        else return iter.hasNext();
    }

    Integer cache = 0;
    boolean cached = false;
    Iterator<Integer> iter;
}
