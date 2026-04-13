
public class Twitter {

    int postNumber = 0;
    HashMap<Integer, HashSet<Integer>> followerMap;
    HashMap<Integer, List<int[]>> postsMap;

    public Twitter() {
        this.followerMap = new HashMap<>();
        this.postsMap = new HashMap<>();
    }

    public void postTweet(int userId, int tweetId) {
        postsMap.putIfAbsent(userId, new ArrayList<>());
        postsMap.get(userId).add(new int[] { tweetId, postNumber++ });
    }

    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);

        List<Integer> userIds = new ArrayList<>();
        userIds.add(userId);
        if (followerMap.get(userId) != null)
            userIds.addAll(followerMap.get(userId));

        for (Integer i : userIds) {
            if (postsMap.get(i) != null) {
                for (int[] post : postsMap.get(i)) {
                    pq.add(post);
                    if (pq.size() > 10)
                        pq.poll(); // remove oldest
                }
            }
        }

        List<Integer> ans = new ArrayList<>();
        while (!pq.isEmpty()) {
            ans.add(pq.poll()[0]);
        }

        Collections.reverse(ans); // latest first
        return ans;
    }

    public void follow(int followerId, int followeeId) {
        followerMap.putIfAbsent(followerId, new HashSet<>());
        followerMap.get(followerId).add(followeeId);
    }

    public void unfollow(int followerId, int followeeId) {
        if (!followerMap.containsKey(followerId))
            return;
        HashSet<Integer> followers = followerMap.get(followerId);
        followerMap.put(followerId, new HashSet<>());
        for (Integer i : followers) {
            if (i != followeeId)
                followerMap.get(followerId).add(i);
        }
    }
}
