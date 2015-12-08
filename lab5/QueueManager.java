import java.util.ArrayList;


public class QueueManager {

    ArrayList<Integer> m_workersIds;
    private int m_currentWorkerIndex;

    public QueueManager(ArrayList<Integer> workersIds) {
        m_workersIds = workersIds;
        m_currentWorkerIndex = 0;
    }

    public void moveToNext() {
        m_currentWorkerIndex++;
        if(m_currentWorkerIndex >= m_workersIds.size()) {
            m_currentWorkerIndex = 0;
        }
    }

    public int getCurrent() {
        return m_workersIds.get(m_currentWorkerIndex).intValue();
    }

}