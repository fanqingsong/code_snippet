from __future__ import print_function

import sys
from pyspark import SparkContext
from pyspark.streaming import StreamingContext

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: wordcounter.py <hostname> <port>", file=sys.stderr)
        exit(-1)
    sc = SparkContext(appName="PythonStreamingStatefulNetworkWordCount1")
    ssc = StreamingContext(sc, 1)
    ssc.checkpoint("file:///usr/local/spark/mycode/streaming/")

    # RDD with initial state (key, value) pairs
    initialStateRDD = sc.parallelize([(u'hello', 1), (u'world', 1)])


    def updateFunc(new_values, last_sum):
        return sum(new_values) + (last_sum or 0)


    lines = ssc.socketTextStream(sys.argv[1], int(sys.argv[2]))
    running_counts = lines.flatMap(lambda line: line.split(" ")) \
        .map(lambda word: (word, 1)) \
        .updateStateByKey(updateFunc, initialRDD=initialStateRDD)

    running_counts.pprint()

    def eachfunc(record):
        eachrecord = "insert into wordcount(word,count) values ('%s', '%s')" % (str(record[0]), str(record[1]))
        print(eachrecord)

    def func(rdd):
        rdd.foreach(eachfunc)

    running_counts.foreachRDD(func)

    ssc.start()
    ssc.awaitTermination()