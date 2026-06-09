public class LRUCache
{
    private Dictionary<int, int> cache = new();
    private Dictionary<int, int> timerToKey = new();
    private Dictionary<int, int> keyToTimer = new();

    private int capacity;
    private int timer;
    private int oldestTimer;

    public LRUCache(int capacity)
    {
        this.capacity = capacity;
        timer = 0;
        oldestTimer = 1;
    }

    public int Get(int key)
    {
        if (!cache.ContainsKey(key))
            return -1;

        int oldTimer = keyToTimer[key];

        timerToKey.Remove(oldTimer);

        keyToTimer[key] = ++timer;
        timerToKey[timer] = key;

        return cache[key];
    }

    public void Put(int key, int value)
    {
        if (cache.ContainsKey(key))
        {
            cache[key] = value;

            int oldTimer = keyToTimer[key];

            timerToKey.Remove(oldTimer);

            keyToTimer[key] = ++timer;
            timerToKey[timer] = key;

            return;
        }

        if (cache.Count == capacity)
        {
            while (!timerToKey.ContainsKey(oldestTimer))
                oldestTimer++;

            int lruKey = timerToKey[oldestTimer];

            timerToKey.Remove(oldestTimer);
            keyToTimer.Remove(lruKey);
            cache.Remove(lruKey);
        }

        cache[key] = value;

        keyToTimer[key] = ++timer;
        timerToKey[timer] = key;
    }
}
