package org.jsontocsv;

import org.apache.commons.io.FileUtils;
import org.jsontocsv.parser.JSONFlattener;
import org.jsontocsv.writer.CSVWriter;

import java.io.File;
import java.util.List;
import java.util.Map;

public class Test {
    public static void main(String[] args) throws Exception {
        List<Map<String, String>> flatJson = JSONFlattener.parseJson(new File("TestData/TestFiles/case10.json"), "UTF-8");
        CSVWriter.writeToFile(CSVWriter.getCSV(flatJson), "TestData/ActuallyOutput/case10.csv");
        //List<Map<String, String>> flatJson = JSONFlattener.parseJson(new File("TestData/TestFiles/case11.json"), "UTF-8");
        //CSVWriter.writeToFile(CSVWriter.getCSV(flatJson), "TestData/ActuallyOutput/case11.csv");
        //List<Map<String, String>> flatJson = JSONFlattener.parseJson(new File("TestData/TestFiles/case12.json"), "UTF-8");
        //CSVWriter.writeToFile(CSVWriter.getCSV(flatJson), "TestData/ActuallyOutput/case12.csv");
        //List<Map<String, String>> flatJson = JSONFlattener.parseJson(new File("TestData/TestFiles/case13.json"), "UTF-8");
        //CSVWriter.writeToFile(CSVWriter.getCSV(flatJson), "TestData/ActuallyOutput/case13.csv");
        //List<Map<String, String>> flatJson = JSONFlattener.parseJson(new File("TestData/TestFiles/case14.json"), "UTF-8");
        //CSVWriter.writeToFile(CSVWriter.getCSV(flatJson), "TestData/ActuallyOutput/case14.csv");
        //List<Map<String, String>> flatJson = JSONFlattener.parseJson(new File("TestData/TestFiles/case15.json"), "UTF-8");
        //CSVWriter.writeToFile(CSVWriter.getCSV(flatJson), "TestData/ActuallyOutput/case15.csv");
        //List<Map<String, String>> flatJson = JSONFlattener.parseJson(new File("TestData/TestFiles/case16.json"), "UTF-8");
        //CSVWriter.writeToFile(CSVWriter.getCSV(flatJson), "TestData/ActuallyOutput/case16.csv");
        //case 17 is not exist.
        //List<Map<String, String>> flatJson = JSONFlattener.parseJson(new File("TestData/TestFiles/case17.json"), "UTF-8");
        //CSVWriter.writeToFile(CSVWriter.getCSV(flatJson), "TestData/ActuallyOutput/case17.csv");

        int pass = 0;
        int fail = 0;

        //test those can output csv file
        File file1 = new File("TestData/ActuallyOutput/case10.csv");
        File file2 = new File("TestData/ExpectedOutput/case10.csv");
        boolean isTwoEqual = FileUtils.contentEquals(file1, file2);
        if(isTwoEqual)
            pass += 1;
        else
            fail += 1;

        File file3 = new File("TestData/ActuallyOutput/case13.csv");
        File file4 = new File("TestData/ExpectedOutput/case13.csv");
         isTwoEqual = FileUtils.contentEquals(file3, file4);
        if(isTwoEqual)
            pass += 1;
        else
            fail += 1;

        File file5 = new File("TestData/ActuallyOutput/case14.csv");
        File file6 = new File("TestData/ExpectedOutput/case14.csv");
         isTwoEqual = FileUtils.contentEquals(file5, file6);
        if(isTwoEqual)
            pass += 1;
        else
            fail += 1;

        File file7 = new File("TestData/ActuallyOutput/case15.csv");
        File file8 = new File("TestData/ExpectedOutput/case15.csv");
         isTwoEqual = FileUtils.contentEquals(file7, file8);
        if(isTwoEqual)
            pass += 1;
        else
            fail += 1;

        File file9 = new File("TestData/ActuallyOutput/case16.csv");
        File file0 = new File("TestData/ExpectedOutput/case16.csv");
        isTwoEqual = FileUtils.contentEquals(file9, file0);
        if(isTwoEqual)
            pass += 1;
        else
            fail += 1;

        //test those can't output csv file
        File file_a = new File("TestData/ActuallyMessages/case11.txt");
        File file_b= new File("TestData/ExpectedMessages/case11.txt");
        isTwoEqual = FileUtils.contentEquals(file_a, file_b);
        if(isTwoEqual)
            pass += 1;
        else
            fail += 1;

        File file_c = new File("TestData/ActuallyMessages/case12.txt");
        File file_d= new File("TestData/ExpectedMessages/case12.txt");
        isTwoEqual = FileUtils.contentEquals(file_c, file_d);
        if(isTwoEqual)
            pass += 1;
        else
            fail += 1;

        File file_e = new File("TestData/ActuallyMessages/case17.txt");
        File file_f= new File("TestData/ExpectedMessages/case17.txt");
        isTwoEqual = FileUtils.contentEquals(file_e, file_f);
        if(isTwoEqual)
            pass += 1;
        else
            fail += 1;

        System.out.print("There is ");
        System.out.print(pass);
        System.out.print(" test case passed, and ");
        System.out.print(fail);
        System.out.print(" test case failed.");

}
}
