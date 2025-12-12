// useless comment at the top


function   testFunction(   a,   b   )    {

        // line comment here

        var total   =     a + b  ;  // another comment

        /*
            block comment
            with lots of spacing
        */

        console.log(     "Total is: "   , total    ) ;     




        return     total   ;
}



function  messyLoop()   {

        /*
        this loop does nothing
        just for minification testing
        */

        for(    var i = 0; i < 10;     i++   ) {
                
                console.log(   "Index:" , i   );   // inline comment
        }


}



// completely unnecessary spaces below







