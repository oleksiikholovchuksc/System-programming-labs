public abstract class MyThread implements Runnable {

    private int m_threadId;
    private Object m_sharedObject;
    private QueueManager m_queueManager;

    public MyThread(int threadId, Object sharedObject, QueueManager queueManager) {
        m_threadId = threadId;
        m_sharedObject = sharedObject;
        m_queueManager = queueManager;
    }

    public int getThreadId() {
        return m_threadId;
    }

    public Object getSharedObject() {
        return m_sharedObject;
    }

    public QueueManager getQueueManager() {
        return m_queueManager;
    }

}