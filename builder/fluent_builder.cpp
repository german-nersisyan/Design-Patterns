#include <iostream>
#include <string>

class Report {

public:
    std::string header;
    std::string body;
    std::string footer;
    
	void show() const
	{
		std::cout << "Report's header: " << header << std::endl;
		std::cout << "Report's body: " << header << std::endl;
		std::cout << "Report's footer: " << header << std::endl;
	}

};

class ReportBuilder {

public:

	virtual ReportBuilder& buildHeader() = 0;
	virtual ReportBuilder& buildBody() = 0;
    virtual ReportBuilder& buildFooter() = 0;
    
    virtual Report* getReport() = 0;
    virtual ~ReportBuilder() = default;
    
};

class PDFReportBuilder : public ReportBuilder {
    
public:

    PDFReportBuilder()
    {
        report = new Report();
    }
    
    virtual ReportBuilder& buildHeader() override 
    {
        report->header = "PDF Header";
        return *this;
    }
    
    virtual ReportBuilder& buildBody() override 
    {
        report->body = "PDF Body";
        return *this;
    }
    
    virtual ReportBuilder& buildFooter() override 
    {
        report->footer = "PDF Footer";
        return *this;
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
    
    virtual ReportBuilder& buildHeader() override 
    {
        report->header = "DOCX Header";
        return *this;
    }
    
    virtual ReportBuilder& buildBody() override 
    {
        report->body = "DOCX Body";
        return *this;
    }
    
    virtual ReportBuilder& buildFooter() override 
    {
        report->footer = "DOCX Footer";
        return *this;
    }
    
    virtual Report* getReport() override
    {
        return report;
    }

private:

    Report* report;

};

int main()
{
    ReportBuilder* pdfbuilder = new PDFReportBuilder();
    Report* pdfreport = pdfbuilder->buildHeader().buildBody().buildFooter().getReport();
    pdfreport->show();
    
    ReportBuilder* docxbuilder = new DOCXReportBuilder();
    Report* docxreport = docxbuilder->buildHeader().buildBody().buildFooter().getReport();
    docxreport->show();
    
    delete pdfreport;
    delete docxreport;
    delete pdfbuilder;
    delete docxbuilder;
	return 0;
}