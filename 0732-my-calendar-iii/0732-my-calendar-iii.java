
class MyCalendarThree {
    TreeMap<Integer, Integer> events;
    
    public MyCalendarThree() {
        this.events = new TreeMap<>(); 
    }

    public int book(int startTime, int endTime) {
        events.put(startTime, events.getOrDefault(startTime, 0) + 1);
        events.put(endTime, events.getOrDefault(endTime, 0) - 1);
        
        int sum = 0;
        int maxy = 0;
        for (Integer e : events.keySet()) {
            sum += events.get(e);
            maxy = Math.max(sum, maxy);
        }
        return maxy;
    }
}
/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(startTime,endTime);
 */