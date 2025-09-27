# Report Builder Pattern Example

This is a C++ implementation of the **Builder Design Pattern** to construct different types of reports (PDF and DOCX).

## Overview

The code shows how the Builder Design Pattern allows the creation of reports in multiple formats (PDF, DOCX) by separating the construction logic from the final object representation. This example is based on a `Report` object, which contains a header, body, and footer.

### Components:

1. **Report Class**: Represents the final object (report) that is being built. It contains the `header`, `body`, and `footer` strings and has a `show()` method to display the content.

2. **ReportBuilder (Abstract Class)**: Defines the abstract interface for building a report. Concrete builders will implement methods to set the header, body, and footer of the report.

3. **PDFReportBuilder**: A concrete builder that constructs a report in PDF format.

4. **DOCXReportBuilder**: A concrete builder that constructs a report in DOCX format.

5. **ReportDirector**: Uses a `ReportBuilder` to construct a report. It orchestrates the sequence of building steps, but it doesn't know the specifics of how each type of report is built.
