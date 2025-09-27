#include <iostream>
#include <string>

class Report {

public:
    std::string header;
    std::string body;
    std::string footer;
    
	void show() const
	{
		std::cout << "Reprort's header: " << header << std::endl;
		std::cout << "Reprort's body: " << header << std::endl;
		std::cout << "Reprort's footer: " << header << std::endl;
	}

};

class ReportBuilder {

public:

	virtual void buildHeader() = 0;
	virtual void buildBody() = 0;
    virtual void buildFooter() = 0;
    
    virtual Report* getReport() = 0;
    
};

class PDFReportBuilder : public ReportBuilder {
    
public:

    PDFReportBuilder()
    {
        report = new Report();
    }
    
    virtual void buildHeader() override 
    {
        report->header = "PDF Header";
    }
    
    virtual void buildBody() override 
    {
        report->body = "PDF Body";
    }
    
    virtual void buildFooter() override 
    {
        report->footer = "PDF Footer";
    }
    
    virtual Report* getReport() override
    {
        return report;
    }

private:

    Report* report;

};

class DOCXReportBuilder : public ReportBuilder {
    
public:

    DOCXReportBuilder()
    {
        report = new Report();
    }
    
    virtual void buildHeader() override 
    {
        report->header = "DOCX Header";
    }
    
    virtual void buildBody() override 
    {
        report->body = "DOCX Body";
    }
    
    virtual void buildFooter() override 
    {
        report->footer = "DOCX Footer";
    }
    
    virtual Report* getReport() override
    {
        return report;
    }

private:

    Report* report;

};

class ReportDirector {

public:
    ReportDirector(ReportBuilder* builder) : builder(builder) {}
    
    void construct()
    {
        std::cout << "Consructing Report" << std::endl;
        builder->buildHeader();
        builder->buildBody();
        builder->buildFooter();
    }

private:

    ReportBuilder* builder;
};

int main()
{
    ReportBuilder* pdfreportbuilder = new PDFReportBuilder();
    ReportDirector* director = new ReportDirector(pdfreportbuilder);
    director->construct();
    Report* pdfreport = pdfreportbuilder->getReport();
    pdfreport->show();
    
    ReportBuilder* docxreportbuilder = new DOCXReportBuilder();
    director = new ReportDirector(docxreportbuilder);
    director->construct();
    Report* docxreport = docxreportbuilder->getReport();
    docxreport->show();
    
    delete pdfreport;
    delete docxreport;
    delete pdfreportbuilder;
    delete docxreportbuilder;
    delete director;
	return 0;
}