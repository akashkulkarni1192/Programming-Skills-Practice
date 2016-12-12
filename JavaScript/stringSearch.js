

var text="Akash is crazy, Akash is calm Anurag is not";
var myName="Akash";
var hits=[];
var k=0;
s="";
for(var i=0;i<text.length;i++){
    if(text[i]===myName[k]){
        /*for(var j=i;j<i+myName.length;j++){
            hits.push(text[j]);
        }*/
        //hits.push(text.substring(i,i+myName.length));
        s[k++]=text[i];
        
    }
    else{
        if(k===myName.length){
            hits.push(s);
            k=0;
        }
        k=0;
    }
}
if(hits.length===0)
    console.log("Your name wasn't found");
else
    console.log(hits.length);