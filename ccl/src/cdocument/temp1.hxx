        eError error = e_ERROR_NONE;
        cDocumentNodeListInterface* of;
        cDocumentElementInterface* of_expr;
        cDocumentElementInterface* name_expr;
        cDocumentElementInterface* element;
        cCCharBuffer name;
        int length;

        if ((of_expr = function.GetFirstElement()))
        if ((name_expr = of_expr->GetNextElement()))
        if ((of = processor.CreateNodeList(error)))
        {
            if (!(error = processor.
                ProcessFunctionElement(*of, *of_expr)))
            if (0 > (length = processor.
                ProcessFunctionElementToText(name, *name_expr)))
                error = -length;
            else if (0 < length)
            {            
                if ((element = of->GetFirstElement()))
                do
                {
                    if ((error = ProcessElementOf
                        (processor, result, *element, name)))
                        break;
                }
                while ((element = element->GetNextElement()));
            }

            processor.DestroyNodeList(*of);
