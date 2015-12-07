public class Main {

    static Object commonObject = new Object();
    static QueueManager commonQueueManager = new QueueManager();
    static final int writerThreadId = 0;
    static final int readerThreadId = 1;

    public static void main(String[] args) {
        Writer writer = new Writer(writerThreadId, commonObject, commonQueueManager);
        Reader reader = new Reader(writerThreadId, commonObject, commonQueueManager);

        writer.run();
        reader.run();
    }

}