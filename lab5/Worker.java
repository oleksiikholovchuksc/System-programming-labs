public abstract class Worker implements Runnable {

    private int m_workerId;
    private SharedMessageStorage m_messageStorage;
    private QueueManager m_queueManager;

    public Worker(int workerId, SharedMessageStorage messageStorage, QueueManager queueManager) {
        m_workerId = workerId;
        m_messageStorage = messageStorage;
        m_queueManager = queueManager;
    }

    public int getWorkerId() {
        return m_workerId;
    }

    public SharedMessageStorage getMessageStorage() {
        return m_messageStorage;
    }

    public QueueManager getQueueManager() {
        return m_queueManager;
    }

    public void waitForTurn() {
        while(m_queueManager.getCurrent() != m_workerId) {
            fallAsleep();
        }
    }

    public void fallAsleep() {
        m_messageStorage.notifyAll();

        try {
            m_messageStorage.wait();
        } catch(InterruptedException e) {}
    }

}