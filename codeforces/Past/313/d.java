import java.util.* ; 
import java.util.Scanner ; 

public class d {
	static String s1,s2 ; 
	 
	
	public static void main (String[] args )  {
		Scanner in = new Scanner ( System.in ) ; 
		s1 = in.nextLine ( ) ;
		s2 =in.nextLine ( ) ; 
		
		if ( s1.length() != s2.length() ){
			System.out.println("NO\n") ; 
			return ; 
		}
		int len  = s1.length() ; 
		
		checkEquivalency  (s1 , s2 , len ) ; 
		
		return 0 ; 
	}
	
   public String firstHalf(String s1 , int len ) {
   		String s = new String() ; 
   		int i ; 
   		for ( i = 0 ; i <len/2 ; i++ ) {
   			s[i]= s1.charAt(i) ; 
   		}
   		return s ; 
   	}
	public String secondHalf(String s2 , int len ) {
   		String s = new String() ; 
   		int i ; 
   		for ( i = 0 ; i <len/2 ; i++ ) {
   			s[i] =  s2.charAt(len/2+i) ; 
   		}
   		return s ; 
   	}
   	
   	public void checkEquivalency (String s1 , String s2 , int length ) {
   		if (length %2 != 0 ) {
   			if ( s1 == s2 ) {
   				System.out.println("YES\n") ; 
   				return ; 
   			}
   			else {
   				System.out.println("NO\n") ; 
   				return ; 
   			}
   		}
   		if (firstHalf(s1, length) ==firstHalf(s2,length) && secondHalf(s1,length) == secondHalf(s2,length)) {
   			System.out.println("YES\n") ;
   			return ;  
   		}
   		if (firstHalf(s1, length) == secondHalf(s2,length) &&  firstHalf(s2,length) == secondHalf(s1,length)){
			System.out.println("YES\n") ;
			return ;  
		}
		System.out.println("YES\n") ; 
		return ; 	
	}	 
		 
		
}		
