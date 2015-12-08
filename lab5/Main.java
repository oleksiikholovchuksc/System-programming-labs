import java.util.ArrayList;


public class Main {

    static SharedMessageStorage messageStorage = new SharedMessageStorage();
    static final int writerThreadId = 0;
    static final int readerThreadId = 1;
    static QueueManager commonQueueManager;

    public static void main(String[] args) {
        ArrayList<Integer> workersIds = new ArrayList<Integer>();
        workersIds.add(new Integer(writerThreadId));
        workersIds.add(new Integer(readerThreadId));

        commonQueueManager = new QueueManager(workersIds);

        new Thread(new Writer(writerThreadId, messageStorage, commonQueueManager)).start();
        new Thread(new Reader(readerThreadId, messageStorage, commonQueueManager)).start();
    }

}